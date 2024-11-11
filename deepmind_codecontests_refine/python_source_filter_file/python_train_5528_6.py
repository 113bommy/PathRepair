def check(st):
    count = 1
    i = 1
    pre = st[0]
    maxi = 0
    pre_indx = 0
    indx = [0 for i in range(n)]
    while i<n:
        if pre != st[i]:
            count+=1
        else:
            indx[pre_indx] =count
            count=1
            pre_indx=i
        pre =st[i]
        i+=1
    indx[pre_indx] =count
    return indx

st=input()
n=len(st)
actual_indx=check(st)
reverse_indx=check(st[::-1])
if st[0] ==st[-1]:
    print(max(actual_indx))
else:
    print(max(max(actual_indx[1:]),actual_indx[0] +reverse_indx[0]))