def f(n,k):
    dig_set = set()
    pre = ''
    for x in n:
        dig_set.add(x)
        if len(dig_set)>int(k): 
            post_head = x
            dig_set.remove(x)
            break
        pre += x
        post_head=""

    post = n[len(pre):] 

    if post_head:
        min_dig = min(dig_set)
        poss_digs = {i for i in dig_set if i>x}
        if poss_digs:
            min_poss_dig = min(poss_digs)
            ans = pre+min_poss_dig+min_dig*(len(post)-1)
        else:
            pre = str(int(pre)+1)
            if len(set(pre))==int(k):
                ans = pre+min(set(pre))*(len(post))
            elif len(set(pre))<int(k):
                ans = pre+"0"*(len(post))
            else:
                ans = f(pre+"0"*(len(post)),k)
    else:
        ans = pre
    
    return ans

for i in range(int(input())):
    n,k = input().split()
    print(f(n,k))