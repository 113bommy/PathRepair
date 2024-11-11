for i in range(int(input())+1,8976):
    if len(set(str(i)))<4:
       i+=1
    else:
       print(i)
       break
