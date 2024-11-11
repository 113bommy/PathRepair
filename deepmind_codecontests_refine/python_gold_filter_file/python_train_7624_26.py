T=int(input())

for _ in range(T):

        a,b=map(int,input().split())

        min_side = min(a,b)

        if min_side*2<max(a,b):
                min_side=max(a,b)
                
        elif min_side*2>max(a,b):
                min_side=min_side*2
        else:
            min_side=max(a,b)

        print(min_side*min_side)