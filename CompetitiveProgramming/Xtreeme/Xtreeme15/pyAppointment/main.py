T = int(input())
for t in range(T):
    N = int(input())

    intervals = []
    # print("new case")
    for i in range(N):
        [li, ri] = [int(el) for el in input().split(' ')]
        intervals.append([li, ri])

    d = {}
    for person, [li, ri] in enumerate(intervals):
        if li in d:
            d[li].append([person+1, li, ri])
        else:
            d[li] = [[person+1, li, ri]]

    visited = {}
    new_intervals = list(d.values())
    # overlaps
    #   person, li, ri
    # sorted(new_intervals, key=lambda x: x[0])
    # print(new_intervals)
    # new_intervals[0].sort(key=lambda x: x[2])
    # print("d:" , d)
    for i in range(1, N+1):
        # print("d:", d)
        # print(f'd[i={i}]:', d[i])
        d[i].sort(key=lambda x: x[2])
        [person, li, ri] = d[i].pop(0)
        could_visit = False
        for j in range(li, ri + 1):
            isDayVisited = j in visited
            if not isDayVisited:
                visited[j] = person
                could_visit = True
                break
        # print('j : ', j)
        if could_visit:
            other_intervals = [[x,y+1,z] for x,y,z in d[i]]
            if len(other_intervals) > 0:
                if (i+1) not in d:
                    d[i+1] = other_intervals
                else:
                    d[i+1] += other_intervals

    if len(visited) != N:
        print('impossible')
    else:
        curr_list = [str(el) for el in list(visited.values())]

        print(" ".join(curr_list))