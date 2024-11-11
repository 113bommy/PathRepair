n=int(input())
a=[int(_) for _ in input().split(" ")]
s,left,right,last="",0,n-1,0
while left<=right:
    min_value=min(a[left],a[right])
    max_value=max(a[left],a[right])
    if (min_value==max_value):
        if min_value>last:
            l,r=left+1,right-1
            left_len,right_len=1,1
            while l<=right:
                if a[l]>a[l-1]:
                    l+=1
                    left_len+=1
                else:
                    break
            while r>=left:
                if a[r]>a[r+1]:
                    r-=1
                    right_len+=1
                else:
                    break
            if left_len>=right_len:
                s=s+"L"*left_len
            else:
                s=s+"R"*right_len
        break
    else:
        if max_value<=last:
            break
        else:
            if min_value>last:
                if a[left]==min_value:
                    s=s+"L"
                    left+=1
                    last=min_value
                else:
                    s=s+"R"
                    right-=1
                    last=min_value
            else:
                if a[left]==max_value:
                    s=s+"L"
                    left+=1
                    last=max_value
                else:
                    s=s+"R"
                    right-=1
                    last=max_value
print(len(s))
print(s)
                
                
