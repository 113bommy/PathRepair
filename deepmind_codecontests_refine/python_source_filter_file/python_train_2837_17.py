def matrix(main,n,m):
    moves = 0
    a = 0
    temp = [0]*m
    for i in main:
        c = 0
        for j in range(m):
            if i[j] == 1:
                c = 1
                temp[j] == 1
        if c == 0:
            moves += 1
    ans = min(moves,temp.count(0))
    
    if ans%2 == 0:
        return 'Vivek'
    else:
        return 'Ashish'
 
    
if __name__ == '__main__':
    for _ in range(int(input())):
        n,m = map(int,input().split())
        main = []
        for _ in range(n):
            r = list(map(int,input().split()))
            main.append(r)
        print(matrix(main,n,m))