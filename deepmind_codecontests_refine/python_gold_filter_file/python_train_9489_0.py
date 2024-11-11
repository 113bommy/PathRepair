n = int(input())
l = [*map(int, input().split())]
res = 0

def dnc(a, b):
    global res
    inc = True
    
    for i in range(a, b):
        if l[i] > l[i+1]:
            inc = False
            break
    
    if inc:
        res = max(res, b-a+1)
    else:
        mid = (a+b)//2
        dnc(a, mid)
        dnc(mid+1, b)

dnc(0, n-1)
print(res)