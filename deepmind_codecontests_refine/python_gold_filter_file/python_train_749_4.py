s = input()
l = len(s)
st = 0
end = l-1
o = []
op=0
while(st<end):
    if(s[st] == '(' and s[end] == ')'):
        o.append(st+1)
        o.append(end+1)
        st+=1
        end-=1
        op+=1

    else:
        if(s[st] == ')'):
            st+=1
        if(s[end] == '('):
            end-=1

if(op == 0):
    print(0)
else:
    print(1)
    print(op*2)
    for i in sorted(o):
        print(i, end = " ")