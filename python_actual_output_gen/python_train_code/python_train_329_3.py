from sys import stdin, stdout

q = int(stdin.readline())
    
for i in range(q):
    n , r = map(int, stdin.readline().split())
    monsters_cord = [int(x) for x in stdin.readline().split()]
    monsters_cord = set(monsters_cord)
    monsters_cord = list(monsters_cord)
    monsters_cord.sort()
    explosions = 0
    for k in range(len(monsters_cord)-1, 0, -1):
        new_monster_cord = monsters_cord[k] - (explosions * r)
        if(new_monster_cord <= 0):
            break
        else:
            explosions += 1
    stdout.write(str(explosions) + "\n")