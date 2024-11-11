t=int(input())
for i in range(t):
    n=int(input())
    input_s=str(input())
    s=list(input_s)
    while n>=2 and s[0] == s[n-1]:
        del s[n-1]
        del s[0]
        n-=2
    s_new=[]
    n_new=n
    for k in range(n):
        s_new.append(s[k])
    if n<=1:
        erased=0
    else:
        del_counter1=1
        del_counter2=1
        erased_el1=s[0]
        erased_el2=s[n-1]
        del s[0]
        n-=1
        while n>=2 and del_counter1 != 999999:
            if s[0] == s[n-1]:
                del s[n-1]
                del s[0]
                n-=2
            elif s[0] == erased_el1:
                del_counter1+=1
                del s[0]
                n-=1
            elif s[n-1] == erased_el2:
                del_counter1+=1
                del s[n-1]
                n-=1
            else:
                del_counter1=999999
        del s_new[n_new-1]
        n_new-=1
        while n_new>=2 and del_counter2 != 999999:
            if s_new[0] == s_new[n_new-1]:
                del s_new[n_new-1]
                del s_new[0]
                n_new-=2
            elif s_new[0] == erased_el2:
                del_counter2+=1
                del s_new[0]
                n_new-=1
            elif s_new[n_new-1] == erased_el2:
                del_counter2+=1
                del s_new[n_new-1]
                n_new-=1
            else:
                del_counter2=999999
        if del_counter1 == 999999 and del_counter2 == 999999:
            erased=-1
        else:
            erased=min(del_counter1, del_counter2)
    print(erased)
    