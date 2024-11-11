n,pos,l,r = list(map(int,input().split()))
answer = 0
if pos == l:
    if pos != 1:
        answer += 1
    if r != n:
        answer += 1+r-l
elif pos == r:
    if pos != n:
        answer += 1
    if l != 1:
        answer += r-l+1
elif pos > r:
    answer = pos -r+1
    if r != n:
        answer += l+r-1
elif pos < l:
    answer = l-pos + 1
    if l != 1:
        answer += 1+r-l
else:
    if l == 1 and r != n:
        answer = r-pos+1
    elif l != 1 and r == n:
        answer = pos-l+1
    elif l != 1 and r != n:
        answer = min(r-pos+1+r-l+1,pos-l+1+r-l+1)
    
print(answer)
