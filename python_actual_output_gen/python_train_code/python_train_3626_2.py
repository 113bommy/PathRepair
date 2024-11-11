string=input()
n=len(string)
check=True
for sub_len in range(n-1,1,-1):
    for starting_index in range(n-sub_len+1):
        if string[starting_index:starting_index+sub_len] in string[starting_index+1:]:
            print(sub_len)
            check=False
            break
    if check==False:
        break  
if check:
    print(0)
