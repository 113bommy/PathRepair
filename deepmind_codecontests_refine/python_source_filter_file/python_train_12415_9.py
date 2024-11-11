import heapq
t = int(input())

def get_tex_bool(a):
    tb = [True]*(len(a)+1)
    for aa in a:
        tb[aa]=False
    ta = []
    for i in range(len(tb)):
        if tb[i]==True:
            ta.append(i)
    return ta

for i in range(t):
    n = int(input())
    a = [int(x) for x in input().split(" ")]
    ta = get_tex_bool(a)
    heapq.heapify(ta)
    ans = []
    for j in range(len(a)):
        if a[j] == j: continue
        else:
            k = j
            while k!=n:
                #print(ta)
                cur = heapq.heappop(ta)
                if a[k] not in a[:k]+a[k+1:]:
                    heapq.heappush(ta, a[k])
                ans.append(k)
                temp = a[k]
                a[k] = cur
                k = temp
    print(len(ans))
    print(" ".join([str(x) for x in ans]))
