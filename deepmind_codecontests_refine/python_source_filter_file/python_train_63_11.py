firstline = input().strip().split(" ")
n = int(firstline[0])
k = int(firstline[1])
bucketspeeds = input().strip().split(" ")

#find largest bucketspeed taht is a factor of keys

largestbucketspeed = 0;
for i in range(n):
	if int(bucketspeeds[i]) > largestbucketspeed:
		if k % int(bucketspeeds[i]) == 0:
			largestbucketspeed = int(bucketspeeds[i])
			
print(k / largestbucketspeed)