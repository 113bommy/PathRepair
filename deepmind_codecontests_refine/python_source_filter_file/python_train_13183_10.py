def main():
   num = input()
   maxi = int(input())
   nl = len(num)
   maxNum = 0
   nums = list(num)
   
   for x in range(len(nums)):
      nums[x] = int(nums[x])
   nums.sort()
   nums = nums[::-1]
   
   if int(str(maxi)[0]) in nums and len(str(maxi))==len(nums):
      nums.remove(int(str(maxi)[0]))
      maxNum = recur(int(str(maxi)[0]), nums, maxi)
      nums.append(int(str(maxi)[0]))
      nums.sort(reverse = True)
   elif len(str(maxi))>len(nums):
      for x in nums:
         maxNum = maxNum*10 + x         
   if maxNum==0 or maxNum>=maxi:
      maxNum = 0
      maxD = (int(str(maxi)[0]))
      a = 0
      for x in nums:
         if x < maxD:
            a = max(x, a)
      maxNum =a
      nums.remove(a)   
      for x in nums:
         maxNum = maxNum * 10 + x
      nums.append(a)
      nums.sort(reverse = True)
   print(maxNum)

   

def recur(curr, poss, maxi):
   maxNum=0
   #print(curr, poss, maxi)
   if len(poss)==0:
      return curr  
   if int(str(maxi)[len(str(curr))]) in poss:
      poss.remove(int(str(maxi)[len(str(curr))]))
      maxNum = recur(curr*10+int(str(maxi)[len(str(curr))]), poss.copy(), maxi)
      poss.append(int(str(maxi)[len(str(curr))]))
      poss.sort(reverse = True)
      
   if maxNum >= maxi or maxNum==0:
      maxD = (int(str(maxi)[len(str(curr))]))      
      a = 0
      for x in poss:
         if x < maxD:
            a = max(x, a)
      if a not in poss:
         return maxi
      #print(maxD, poss, a, maxi, curr)
      curr = curr*10 + a
      poss.remove(a)   
      for x in poss:
         curr = curr * 10 + x
      poss.append(maxD)
      poss.sort(reverse = True)
      return curr
   else:
      return maxNum

main()
   