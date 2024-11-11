test_str = input()
 
all_freq = {} 
 
for i in test_str: 
    if i in all_freq: 
        all_freq[i] += 1
    else: 
        all_freq[i] = 1
 
ans=0
for k in all_freq.keys():
   #print (k, all_freq[k])
   ans=ans+(all_freq[k]*all_freq[k])
print(ans)
#print ("Count of all characters in String is :\n "
#                                       +  str(all_freq)) 