class Point:
    def __init__(self, x: int = 0, y: int = 0):
        self.x = x
        self.y = y


    def __str__(self):
        return f'Point: ({self.x}, {self.y})'
    

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y


counter = 0
xvect = {
        'L': -1,
        'R': 1,
        'U': 0,
        'D': 0
        }
yvect = {
        'L': 0,
        'R': 0,
        'U': 1,
        'D': -1
}
visited: list[Point] = []


def getmoves(location: Point, letter: str):
    x, y = location.x, location.y
    result: list[str] = []

    if (letter != '?'):
        result.append(letter)
    else:
        if x > 0:
            move = 'L'
            newp = Point(x + xvect[move], y + yvect[move])
            isvisited = newp in visited
            if not isvisited:
                result.append(move)
        if x < 6:
            move = 'R'
            newp = Point(x + xvect[move], y + yvect[move])
            isvisited = newp in visited
            if not isvisited:
                result.append(move)
        if y < 6:
            move = 'U'
            newp = Point(x + xvect[move], y + yvect[move])
            isvisited = newp in visited
            if not isvisited:
                result.append(move)
        if y > 0:
            move = 'D'
            newp = Point(x + xvect[move], y + yvect[move])
            isvisited = newp in visited
            if not isvisited:
                result.append(move)
    return result


def moveto(point: Point, direction: str):
    newp = Point(point.x + xvect[direction], point.y + yvect[direction])
    return newp


def main(fullpath: str, loc: Point = Point(0, 6), pos: int = 0):
    global counter
    visited.append(loc)

    if pos == 48 and loc == Point():
        counter += 1
        visited.pop()
        return
    
    if pos >= 48:
        print(loc)
        visited.pop()
        return
    
    x, y = loc.x, loc.y
    moves = getmoves(loc, fullpath[pos])
    if moves == [] or x > 6 or y > 6 or x < 0 or y < 0:
        print(loc)
        visited.pop()
        return
    
    for move in moves:
        newp = moveto(loc, move)
        main(fullpath, newp, pos + 1)


if __name__ == '__main__':
    # path = input()
    path = "??????R??????U??????????????????????????LD????D?"
    # path = "D?URRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD"

    main(path)
    print(counter)
