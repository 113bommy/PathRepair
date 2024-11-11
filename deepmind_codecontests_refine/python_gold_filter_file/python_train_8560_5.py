def defeatDragon(x, n, m):
    if x <= 0:
        print('YES')
        return True
 
    if n > 0:
        return defeatDragon((x//2)+10, n-1, m)
    if m > 0:
        return defeatDragon(x-10, n, m-1)
 
 
def main():
    t = int(input())
    while t > 0:
        x, n, m = tuple((map(int, input().split())))
        if x-(m*10) <= 0:
            print('YES')
        elif not defeatDragon(x, n, m):
            print('NO')
        t-=1

main()