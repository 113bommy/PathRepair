tests = int(input())
for t in range(tests):
    n = int(input())
    ls = list(map(int, input().split()))
#    ls_1 = sum(ls)//len(ls)
    ls_others = [2**i for i in range(0,30)]
    ans = []
    for item in ls:
        for sel_idx in range(len(ls_others)):
            if sel_idx < (len(ls_others)-1):
                if abs(item-ls_others[sel_idx]) <= abs(item-ls_others[sel_idx+1]):
                    ans.append(ls_others[sel_idx])
                    break
            else:
                ans.append(ls_others[sel_idx])
        
    print(' ' .join([str(item) for item in ans]))
#    print(sum(ls))
#    print(sum([abs(ans[i]-ls[i]) for i in range(len(ans))]))