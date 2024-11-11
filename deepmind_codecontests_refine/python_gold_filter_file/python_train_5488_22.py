from collections import defaultdict
def output(strs2, n):
    if len(strs2) != n:
        print("NO")
        return
    
    for i in range(n):
        for j in range(i+1,n):
            if strs2[i] not in strs2[j]:
                print("NO")
                return
    print("YES")
    print('\n'.join(strs2))
    
def main():
    n = int(input())
    strs = []
    for i in range(n):
        strs.append(input())
    out_edge = defaultdict(set)
    in_edge = defaultdict(lambda: 0)
    for i in range(n):
        for j in range(i+1, n):
            if strs[i] in strs[j] and strs[i] != strs[j]:
                out_edge[i].add(j)
                in_edge[j] += 1
            if strs[j] in strs[i] and strs[i] != strs[j]:
                out_edge[j].add(i)
                in_edge[i] += 1
    # print(out_edge)
    # print(in_edge)
    dq = [i for i in range(len(strs)) if in_edge[i] == 0] 
    ans = dq[:]
    # print(dq)
    while dq:
        new_dq = []
        for src in dq:
            for dst in out_edge[src]:
                in_edge[dst] -= 1
                if in_edge[dst] == 0:
                    new_dq.append(dst)
                    ans.append(dst)
        dq = new_dq
    strs2 = [strs[i] for i in ans]
    output(strs2, n)

                
                
            

if __name__ == '__main__':
    main()
    