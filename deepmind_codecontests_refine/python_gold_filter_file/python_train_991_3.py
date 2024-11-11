n = int(input())
T = [0]+list(map(int, input().split()))+[90]
ok = 1
for i in range(1,n+2):
    if T[i]-T[i-1]>15:
        print(T[i-1]+15)
        ok = 0
        break
if ok:
    print(90)
