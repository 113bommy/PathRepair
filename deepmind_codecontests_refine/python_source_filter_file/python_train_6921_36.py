n = int(input())
t = list(map(int,input().split()))


tmp = [0]*n
cnt1 = 1
cnt2 = 1

def counting_sort(array, maxval):
    """in-place counting sort"""
    m = maxval + 1
    count = [0] * m               # init with zeros
    for a in array:
        count[a] += 1             # count occurences
    i = 0
    for a in range(m):            # emit
        for c in range(count[a]): # - emit 'count[a]' copies of 'a'
            array[i] = a
            i += 1
    return (array)
if max(t)>500000:
    t.sort()
else:
    t = counting_sort(t,max(t))
def foo(x,n):
    tmp = [0]*n
    cnt2 = 1
    for i in range(1,n):
        tmp[i] = sum(x[:i])
        if tmp[i]<=x[i]:
            cnt2+=1
    return cnt2
'''
for i in range(1,n):
    tmp[i] = sum(t[:i])
    if tmp[i]<=t[i]:
        cnt1+=1
'''
"""for i in range(1,n):
    tmp[i] = sum(x[:i])
    if tmp[i]<=x[i]:
        cnt2+=1
    else:
        if len(x[i:])>=len(x[:i]):
            if x[i]<=x[i-1]:
                print(len(x[i-1:]))
                quit()
print(cnt2)"""
#print(max(cnt1,cnt2),cnt1,cnt2)
c = 0
for i in range(1,n):
    if t[i]>=c:
        cnt2+=1
        c+=t[i]
    '''tmp[i] = sum(t[:i])
    if tmp[i]<=t[i]:
        cnt2+=1
    else:
        t[i] = 0'''

print(cnt2)