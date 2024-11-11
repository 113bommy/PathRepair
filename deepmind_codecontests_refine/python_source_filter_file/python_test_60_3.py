def cast(cre, typ):
    return type(typ)(map(cre, typ));
def inp_lis(cre):
    if cre == str: return input().split();
    elif cre == bool: return cast(bool, cast(int, input().split()));
    else: return cast(cre, input().split());
def repl(s, i = -1, ch = ""):
    return s[:i] + ch + s[(len(s)+i)%len(s)+1:];

def solution():
    for t in range(int(input())):
        n = int(input()); arr = inp_lis(int); avg2x = (sum(arr)/n)*2;
        dic = {}; ans = 0; k, v = 0, 1;

        for i in range(n):
            if arr[i] in dic: dic[arr[i]] += 1;
            else: dic[arr[i]] = 1;
        
        dic_sorted_keys = sorted(dic.keys()); idx = 0;
        while len(dic_sorted_keys) > idx:
            if avg2x - dic_sorted_keys[idx] in dic:
                if dic_sorted_keys[idx] == avg2x - dic_sorted_keys[idx]:
                    n = dic[dic_sorted_keys[idx]]-1; ans += (n*n+n)/2;
                    del dic[dic_sorted_keys[idx]];
                else:
                    ans += dic[dic_sorted_keys[idx]] * dic[avg2x - dic_sorted_keys[idx]];
                    del dic[dic_sorted_keys[idx]];
                    del dic[avg2x - dic_sorted_keys[idx]];
            idx += 1;
        else: print(ans);
    return;
solution();