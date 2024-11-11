def solution(a,b,c):
    ans = [0,0]
    if c <= a :
        ans[0] = -1
        ans[1] = b 
        
    elif b * a == c :
        if b == 1 :
            ans[0] = -1
        else:
            ans[0] = b + 1 
            
        ans[1] = - 1 
    else:
        ans[0] = 1 
        cond = True 
        val = 1
        if a > c/b :
            while cond  :
                cost1 = a * b * val 
                cost2 = c * val 
                if cost2 < cost1 :
                    ans[1] = b*val 
                    cond =False 
                val = val + 1
        else:
            ans[1] = -1 
    return ans 
for _ in range(int(input())):
    a,b,c = map(int,input().split())
    ans  = solution(a,b,c)
    print(*ans )