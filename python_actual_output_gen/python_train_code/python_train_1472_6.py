n = int(input())
init = 10
res=0
if(n%2==0):
    while init < n:
        res += n//init
        init*=5

print(res)
