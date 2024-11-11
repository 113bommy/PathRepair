def tax(p,x):
    return p*(100+x) // 100 # 整数除算

def solve(X,Y,S):
    ans = 0
    oldsum = 0
    newsum = 0
    for a in range(1,S):
        for b in range(1,S-a+1): #税抜き価格a,bの総和はS以下である
            oldsum = tax(a,X)+tax(b,X) #税制改定前の税込合計額
            if oldsum == S: # 新税でのtax(a,Y)+tax(b,Y) について検討 
                newsum = tax(a,Y)+tax(b,Y) 
                if newsum > ans:
                    ans =newsum
            if oldsum > S:
                break # b増加ならばsum増加のため
    return ans

while True:
    X,Y,S = map(int, input().split())
    if a == 0:
        break
    print(solve(X,Y,S))
