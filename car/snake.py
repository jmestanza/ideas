import pygame

white = (255, 255, 255)
red = (255, 0, 0)
green = (0, 255, 0)
black = (0, 0, 0)
bright_red = (255,0,0)
bright_green = (0,255,0)

display_width = 800
display_height = 600


def Button1Update(mouse, click, menu):
    if 150 + 100 > mouse[0] > 150 and 450 + 50 > mouse[1] > 450 and click[0] == 1:
        pygame.draw.rect(gameDisplay, red, (150, 450, 100, 50))
        menu[0] = "play"
    else:
        pygame.draw.rect(gameDisplay, green, (150, 450, 100, 50))


def text_objects(text, font):
    textSurface = font.render(text, True, black)
    return textSurface, textSurface.get_rect()


def game_intro():
    intro = True
    menu = ["start"]
    carImg = pygame.image.load('descarga.jpg')
    x = 200
    y = 200
    flip_x = 0
    flip_y = 0
    last_flip_x = 0
    last_flip_y = 0
    changed = "HORIZONTAL"
    base = pygame.transform.flip(carImg, flip_x, flip_y)
    while intro:
        for event in pygame.event.get():
            #print(event)
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
        delta_x = 0
        delta_y = 0

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                delta_x = -5
                flip_x = 1
                changed = "HORIZONTAL"

            if event.key == pygame.K_RIGHT:
                delta_x = 5
                flip_x = 0
                changed = "HORIZONTAL"

            if event.key == pygame.K_UP:
                delta_y = -5
                flip_y = 1
                changed = "VERTICAL"
            if event.key == pygame.K_DOWN:
                delta_y = 5
                flip_y = 0
                changed = "VERTICAL"

        if menu[0] == "start":
            gameDisplay.fill(white)
            largeText = pygame.font.Font('freesansbold.ttf', 115)
            TextSurf, TextRect = text_objects("Snake", largeText)
            TextRect.center = ((display_width / 2), (display_height / 2))
            gameDisplay.blit(TextSurf, TextRect)
            mouse = pygame.mouse.get_pos()
            click = pygame.mouse.get_pressed()
            Button1Update(mouse, click, menu)
            if event == pygame.MOUSEBUTTONUP: #mouse button up
                menu[0] = "play"
        elif menu[0] == "play":
            gameDisplay.fill((255, 255, 255))
            x += delta_x
            y += delta_y
            if changed == "HORIZONTAL":
                if flip_x != last_flip_x:
                    aux = pygame.transform.flip(carImg, flip_x, flip_y)
                    last_flip_x = flip_x
                else: #si sigue siendo el mismo
                    aux = pygame.transform.flip(carImg, last_flip_x, last_flip_y)
            elif changed == "VERTICAL":
                if flip_y != last_flip_y:
                    aux = pygame.transform.rotate(carImg, flip_y * 90)
                    last_flip_y = flip_y
                else:
                    if last_flip_y == 1:
                        angle = 90
                    else:
                        angle = 270
                    aux = pygame.transform.rotate(carImg, angle)

            gameDisplay.blit(aux, (x, y))

        pygame.display.update()
        clock.tick(15)


pygame.init()
gameDisplay = pygame.display.set_mode((800, 600))
clock = pygame.time.Clock()
game_intro()
