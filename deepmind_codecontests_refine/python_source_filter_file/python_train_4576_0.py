def move(act,y,x,direction):#戦車の動き
    #print("x,y",y,x)
    #print("M,H",M,H)
    if x<0 or x == M or y<0 or y == H:
        return s_map
    if act == 'U':#Up
        if y == 0:
            s_map[y][x] = '^'
        else:
            if s_map[y-1][x] == '.':#下が平地なら
                s_map[y][x],s_map[y-1][x] = '.','^'#現在地と下を入れ替える
            else:
                s_map[y][x] = '^'
    elif act == 'D':#Down
        if y == H-1:
            s_map[y][x] = 'v'
        else:
            if s_map[y+1][x] == '.':#下が平地なら
                s_map[y][x],s_map[y+1][x] = '.','v'#現在地と下を入れ替える
            else:
                s_map[y][x] = 'v'

    elif act == 'L':#Left
        if x == 0:
            s_map[y][x] = '<'
        else:
            if s_map[y][x-1] == '.':#左が平地なら
                s_map[y][x],s_map[y][x-1] = '.','<'#現在地と左を入れ替える
            else:
                s_map[y][x] = '<'

    elif act == 'R':#Right
        if x == M-1:
            s_map[y][x] = '>'
        else:
            if s_map[y][x+1] == '.':#右が平地なら
                s_map[y][x],s_map[y][x+1] = '.','>'#現在地と右を入れ替える
            else:
                s_map[y][x] = '>'

    else:#Shoot
        now_dir = s_map[y][x]
        ma = shoot(y,x,now_dir)
        return ma
    
def shoot(y,x,now_dir):
    if x<0 or y<0 or x==M or y==H:
        return s_map
    if now_dir == '>':#戦車が右を向いていたら
        while True:
            #再帰かな x+=1　右の地面を見ていく
            if s_map[y][x] == '*':
                s_map[y][x] = '.'
                break
            elif s_map[y][x] == '#':
                break
            else:
                shoot(y,x+1,now_dir)
            break

    elif now_dir == '<':#戦車が左を向いていたら
        while True:
            #再帰かな x-=1　左の地面を見ていく
            if s_map[y][x] == '*':
                s_map[y][x] = '.'
                break
            elif s_map[y][x] == '#':
                break
            else:
                shoot(y,x-1,now_dir)
            break
       
    elif now_dir == '^':
        while True:
            #再帰かな y-=1　右の地面を見ていく
            if s_map[y][x] == '*':
                s_map[y][x] = '.'
                break
            elif s_map[y][x] == '#':
                break
            else:
                shoot(y-1,x,now_dir)
            break

    elif now_dir == 'v':
        while True:
            #再帰かな y+=1　右の地面を見ていく
            if s_map[y][x] == '*':
                s_map[y][x] = '.'
                break
            elif s_map[y][x] == '#':
                break
            else:
                shoot(y+1,x,now_dir)
            break

def search_index(s_map):#現在地のインデックスと方向を確認
    direction = ['^','v','>','<']
    for i in range(len(direction)):
        for j in range(len(s_map)):
            for k in range(len(s_map[0])):
                if direction[i] in s_map[j][k]:
                    x,y,d = j,k,direction[i]

    return x,y,d


if __name__== '__main__':
    T = int(input())#全体回数
    all_map=[]
    for i in range(T):
        s_map = []
        H,M = map(int,input().split())#マップの縦幅横幅
        for j in range(H):#マップ作成
            s_map.append([i for i in input()])
        N = int(input())#何回処理を行うか
        action = input()#アクション文字列
        for k in action:
            x,y,direction = search_index(s_map)
            #print("Now state (x,y)",y,x)
            #print(direction)
            #print("action = ",k)
            m  = move(k,x,y,direction)
        all_map.append(s_map)
    for j in range(len(all_map)):
        for i in range(len(all_map[j])):
            print(''.join(all_map[j][i]))
        if j != len(all_map)-1:
            print(" ")

