def mm(s):
    arr=[]
    for i in range(len(s)):
        arr.append(s[i])
    return arr
s1 = input()
s2 = input()
s3 = input()
make = s1+s2
arr1 = mm(make)
arr2 = mm(s3)
arr1.sort()
arr2.sort()
m = True
if len(arr1)<=len(arr2):
    for i in range(len(arr1)):
        if arr1[i]!=arr2[i]:
            print("NO")
            m = False
            break
    if m:
        print("YES")
else:
    print("NO")

