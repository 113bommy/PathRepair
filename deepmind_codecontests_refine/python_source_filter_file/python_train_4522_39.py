def get_pos(s: str):
    x = s[0]
    y = s[1]
    if not x.isdigit():
        x = str(ord(x)-ord('a')+1)
    if not y.isdigit():
        y = str(ord(y)-ord('a')+1)
    return int(x),int(y)

def solve(start, end):
    start_x, start_y = get_pos(start)
    end_x, end_y = get_pos(end)
    min_val= 100000000
    res = []
    while start_x != end_x or start_y != end_y:
        arr = [
            (start_x, start_y+1, 'U'),
            (start_x,start_y-1, 'D'),
            (start_x-1, start_y, 'L'),
            (start_x+1, start_y, 'R'),
            (start_x-1, start_y-1,'LU'),
            (start_x-1, start_y+1, 'LD'),
            (start_x+1, start_y-1, 'RD'),
            (start_x+4, start_y+1, 'RU')
        ]
        selected_min = None
        for ver in arr:
            if ((ver[0]-end_x)**2 + (ver[1]-end_y)**2)**.5 < min_val:
                min_val = ((ver[0]-end_x)**2 + (ver[1]-end_y)**2)**.5
                selected_min = ver
                start_x = ver[0]
                start_y = ver[1]
        res.append(selected_min[2])
    print(len(res))
    print(*res, sep='\n')

def main():
    # vars = list(map(int, input().split(" ")))
    start = input()
    end = input()

    # s = input()
    # a = list(map(int, input().split(" ")))
    # b = list(map(int, input().split(" ")))
    # c = list(map(int, input().split(" ")))
    # res = []
    # for _ in range(n):
    #     arr = list(map(int, input().split(" ")))
    #     res.append(saveThePrisoner(*arr))
    # print(*res,sep='\n')
    solve(start,end)


main()
