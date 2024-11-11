#input for the string for code
code=input()
curr=code[0]
curr_count=1
add_count=0
n=len(code)
for i in range(1,n):
    if code[i]==curr:

        curr_count+=1
        if i==n-1:
            if curr_count%2==0:
                add_count+=1
                # print("There was even number of:"+code[i-1])

    else:
        curr=code[i]

        #if even number
        if curr_count%2==0:
            add_count+=1
            # print("There was even number of:"+code[i-1])
        curr_count=1
    # print("curr is now:"+str(curr))
    # print("curr_count is now:"+str(curr_count))
print(add_count)
