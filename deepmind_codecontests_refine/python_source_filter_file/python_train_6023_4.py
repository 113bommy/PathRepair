# coding: utf-8
# Your code here!
H,W=map(int,input().split())

def calc(main,sub):
    if main%3==1:
        a=main//3
    else:
        a=main//3+1
    b=sub//2
    temp=[a*sub,(main-a)*b,(main-a)*(sub-b)]
    
    return max(temp)-min(temp)
        

if H%3==0 or W%3==0:
    print(0)
else:
    print(min(calc(H,W),calc(W,H),sub,main))
    
