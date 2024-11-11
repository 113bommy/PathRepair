n = int(input())

min = list(map(int,input().split(" ")))[:n]

if min[0] > 15 :
    print(15)
else :
    for i in range(len(min)-1):
        if min[i+1] - min[i] >= 15:
            print(min[i]+15)
            break
    else:
        print(min[-1] if 90 - min[-1] >= 15 else 90)
            
