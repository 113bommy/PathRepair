n=int(input())
s=input()

if 'R' not in s:
    for i in range(n-1,-1,-1):
        if s[i]=='L':
            st=i+1
            end=s.index('L')-1
            break

elif 'L' not in s:
    for i in range(n-1,-1,-1):
        if s[i]=='R':
            end=i+1
            st=s.index('R')+1
            break
else:
    st = s.index('R') + 1
    end = s.index('L')
print(st,end+1)
