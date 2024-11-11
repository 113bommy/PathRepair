for t in range(1):
    n=int(input())
    arr=list(map(int,input().split()))
    counter=dict()
    for i in arr:
        if i in counter:
            counter[i]+=1
        else:
            counter[i]=1
    happy=0
    satis=0
    ans=1
    q=int(input())
    arr_lang=list(map(int,input().split()))
    arr_sub=list(map(int,input().split()))
    for i in range(q):
        lang,sub=arr_lang[i],arr_sub[i]
        count_lang=0
        count_sub=0
        if lang in counter:
            count_lang=counter[lang]
        if sub in counter:
            count_sub=counter[sub]
        if count_lang>happy:
            happy=count_lang
            satis=count_sub
            ans=i+1
        elif count_lang==happy and count_sub>satis:
            satis=count_sub
            ans=i+1
        else:
            continue
    print(ans)