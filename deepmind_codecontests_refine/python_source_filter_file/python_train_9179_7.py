# *-* coding=utf-8 *-*


input()
s = input()
ans = 0
l = list(s)
for i in range(len(l)//2):
    if l[2*i-1] == l[2*i]:
        ans += 1
        if l[2*i] == 'a': l[2*i] = 'b'
        else: l[2*i] = 'a'
print(ans, ''.join(l), sep='\n')




