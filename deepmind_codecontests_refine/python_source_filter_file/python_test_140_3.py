s2 = 2
s3 = 2
a_list = [1]
while a_list[-1]<1e9:
    if s2*s2<s3*s3*s3:
        a_list.append(s2*s2)
        s2 += 1
    elif s2*s2>s3*s3*s3:
        a_list.append(s3*s3*s3)
        s3 += 1
    else:
        a_list.append(s2*s2)
        s2 += 1
        s3 += 1

def getResult(m):
    for i in range(len(a_list)):
        if a_list[i]>m:
            return i

n = int(input())
for i in range(n):
    m = int(input())
    print(getResult(m))