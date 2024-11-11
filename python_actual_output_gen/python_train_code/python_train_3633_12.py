if __name__=='__main__':
    string = list(input())
    tests = int(input())
    for i in range(tests):
        l,r,times = map(int,input().split())
        l-=1
        temp = string[l:r]
        #check = [i for i in range(len(temp))]
        
        #print("temp is ",temp)
        k = (times-1)%(r-l)
        for i in range(len(temp)):
            k +=1
            k = k%(r-l)
           # print("mark-> ",l+k)
            string[l+k]=temp[i]
            
       
        print(''.join(string))
