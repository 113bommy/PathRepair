def solution(n,a,p):
    result = []
    r=[]
    a.sort()
    for i in range(n):
        r.append(-a[i]+i+1)
    # print(r)
    remainder = []
    for i in range(p):
        remainder.append(0)
    for i in range(p-1,n):
        # print(r[i])
        n_a_re = (p - r[i])%p
        remainder[n_a_re] += 1
    # print(remainder)
    min_x = 1-n+a[n-1]
    for i in range(2,n):
        if(i-n+a[n-i]>min_x):
            min_x = i-n+a[n-i]
    result += get_x(min_x,a[p-1],remainder,p,n,p-2)
    
    return result

def get_x(start,end,remainder,p,n,id):
    v1 = start//p
    r1 = start%p
    v2 = end//p
    r2 = end%p
    # print(start,end)
    arr = []
    s_id = -1
    e_id = -1
    if(end>start):
        for i in range(len(remainder)):
            if(remainder[i]==0):
                # print('select',v1*p + i)
                arr.append(v1*p + i)
                if(i>=r1 and s_id == -1):
                    s_id = len(arr)-1
                if(i>=r2 and e_id == -1):
                    e_id = len(arr) - 1
        period = len(arr)
        for _ in range((v2-v1)*period):
            arr.append(arr[-period]+p)
        if(s_id == -1):
            s_id = period
        if(e_id == -1):
            e_id = period
        remainder[(p+end-id-2)%p] -= 1
        # print('remainder',remainder)
        # print(arr[s_id:len(arr)-period+e_id])
        return arr[s_id:len(arr)-period+e_id]
    else:
        remainder[(p+end-id-2)%p] -= 1
        # print('remainder',remainder)

        return []


num = input()
num = num.split(" ")
n = int(num[0])
p = int(num[1])
a = list(map(int,input().split(" ")))
result = solution(n,a,p)
print(len(result))
print(" ".join(list(map(str,result))))