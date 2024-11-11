import sys
def dfs(tiles, W, H, x, y):
    tiles[y][x] = '0'
    for dx,dy in ((-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1)):
        if 0<=x+dx<W and 0<=y+dy<H and tiles[y+dy][x+dx]=='1':
            dfs(tiles, W, H, x+dx, y+dy)
    return

def main():
    while True:
        W,H = [int(x) for x in input().split()]
        if W==0 and H==0:
            exit()
        tiles = [[c for c in input().split()] for h in range(H)]
        cnt = 0
        for h in range(H):
            for w in range(W):
                if tiles[h][w] == '1':
                    cnt += 1
                    dfs(tiles, W, H, w, h)
        print(cnt)

if __name__ == '__main__':
    sys.setrecursionlimit(100000)
    main()