import pygame
import numpy as np

class Pos:
    def __init__(self, x,y):
        self.x = x
        self.y = y

class Square:
    def __init__(self, isHead, pos):
        self.pos = Pos(pos.x, pos.y)
        self.isHead = isHead

class Food:
    def __init__(self, init_pos):
        self.FoodsEaten = 0
        self.pos = Pos(init_pos.x, init_pos.y)
        self.square_size = 20
        self.background = pygame.image.load('fondo.JPG')
        self.background = pygame.transform.scale(self.background, (self.square_size, self.square_size))

    def resetFood(self):
        self.FoodsEaten = 0

    def isEaten(self, pos_snake):
        return (pos_snake.x == self.pos.x) and (pos_snake.y == self.pos.y)

    def getNewFoodPos(self):
        x = np.random.randint(low=0,high=display_width +1 - self.square_size)
        x = x + (self.square_size - (x % self.square_size))
        y = np.random.randint(low=0,high=display_height +1 - self.square_size)
        y = y + (self.square_size - (y % self.square_size))
        self.pos = Pos(x, y)

    def drawFood(self):
        gameDisplay.blit(self.background, (self.pos.x, self.pos.y))

class Snake:

    def __init__(self, name, xlims, ylims, init_pos, head_img, not_head_img, background):
        self.square_size = 20
        self.background = pygame.transform.scale(background, (self.square_size, self.square_size))
        self.head_img = pygame.transform.scale(head_img, (self.square_size, self.square_size))
        self.not_head_img = pygame.transform.scale(not_head_img, (self.square_size, self.square_size))
        self.name = name
        self.last_direction = 'No dir'
        self.direction = 'right'
        self.moving = False
        self.pos = init_pos
        dx,dy = self.getDeltas()
        self.body = [Square(True,init_pos),
                     Square(False,Pos(init_pos.x-dx*self.square_size
                                      ,init_pos.y-dy*self.square_size))] # le paso la misma de la head

        self.limits_x = []
        self.limits_y = []
        for xlim in xlims:
            self.limits_x.append(xlim)
        for ylim in ylims:
            self.limits_y.append(ylim)

    def getDeltas(self):
        delta_x = 0
        delta_y = 0
        if self.direction == 'right':
            delta_x = -1
        elif self.direction == 'left':
            delta_x = 1
        elif self.direction == 'up':
            delta_y = 1
        elif self.direction == 'down':
            delta_y = -1
        return delta_x,delta_y

    def getPositions(self):
        if self.moving == True:
            dx,dy = self.getDeltas()
            last_pos_x = self.body[0].pos.x
            last_pos_y = self.body[0].pos.y
            for i in range(1,len(self.body)):
                new_last_post_x = self.body[i].pos.x
                self.body[i].pos.x = last_pos_x
                last_pos_x = new_last_post_x

                new_last_post_y = self.body[i].pos.y
                self.body[i].pos.y = last_pos_y
                last_pos_y = new_last_post_y

            self.body[0].pos.x -= dx * self.square_size
            self.body[0].pos.y -= dy * self.square_size

    def Collisioned(self):
        ans = False # asumimos que no colisionamos
        for el in self.body:
            for xlim in self.limits_x:
                if el.pos.x == xlim:
                    ans = True
            for ylim in self.limits_y:
                if el.pos.y == ylim:
                    ans = True
        for i in range(1,len(self.body)):
            if self.body[0].pos.x == self.body[i].pos.x and \
                    self.body[0].pos.y == self.body[i].pos.y:
                ans = True
        return ans

    def updateDir(self,tecla):

        if tecla == pygame.K_DOWN:
            self.direction = 'down'
        elif tecla == pygame.K_UP:
            self.direction = 'up'
        elif tecla == pygame.K_LEFT:
            self.direction = 'left'
        elif tecla == pygame.K_RIGHT:
            self.direction = 'right'

        if self.direction == 'up' and self.last_direction == 'down':
            self.direction = 'down'
        if self.direction == 'down' and self.last_direction == 'up':
            self.direction = 'up'
        if self.direction == 'right' and self.last_direction == 'left':
            self.direction = 'left'
        if self.direction == 'left' and self.last_direction == 'right':
            self.direction = 'right'

        self.last_direction = self.direction

    def drawSnake(self):
        gameDisplay.blit(self.head_img, (self.body[0].pos.x, self.body[0].pos.y))
        for i in range(1, len(self.body)):
            gameDisplay.blit(self.not_head_img, (self.body[i].pos.x, self.body[i].pos.y))

    def addNewTail(self):
        last_px = -100 # valores invalidos
        last_py = -100
        self.body.append(Square(False, Pos(last_px, last_py)))


def game_intro(display_height,display_width):
    intro = True
    snake_obj = Snake(name='Snake_1', xlims=[0, display_width],
                      ylims=[0, display_height],
                      init_pos=Pos(200,200),
                      head_img = pygame.image.load('head.JPG'),
                      not_head_img= pygame.image.load('body.JPG'),
                      background= pygame.image.load('fondo.JPG'))
    snake_obj.moving = True

    food_obj = Food(Pos(100,100))

    while intro:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
                intro = False
            if event.type == pygame.KEYDOWN:
                snake_obj.updateDir(tecla=event.key)
        if snake_obj.Collisioned():
            print('GAME OVER')
            intro = 1
        else:
            gameDisplay.fill((255, 255, 255))
            snake_obj.getPositions() # avanzo con head

            if food_obj.isEaten(snake_obj.body[0].pos): # si como
                food_obj.getNewFoodPos() # agrego una nueva posicon de comida
                snake_obj.addNewTail() # agrego una cola

            snake_obj.drawSnake() #dibujo la snake
            food_obj.drawFood()

        pygame.display.update()
        clock.tick(5)


white = (255, 255, 255)
red = (255, 0, 0)
green = (0, 255, 0)
black = (0, 0, 0)
bright_red = (255,0,0)
bright_green = (0,255,0)
display_width = 600
display_height = 400
pygame.init()
gameDisplay = pygame.display.set_mode((display_width, display_height))
clock = pygame.time.Clock()
game_intro(display_height,display_width)
