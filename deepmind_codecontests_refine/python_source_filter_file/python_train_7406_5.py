'''https://codeforces.com/contest/1141/problem/B

Line 1 of input gives number of hours in day
Line 2 gives a sequence of integers representing rest (1) or work (0) in each hour, for each day.

Print the number of continuous hours of rest you can have, across multiple days.
'''

#Make a list of the hours
hours = int(input('p1'))
day = input('p2').split(' ')

#To make sure we account for cross-day rest sequences, we want to rearrange the list to start with work.
day = day[day.index(str(0)):] + day[:day.index(str(0))]

#Now find the length of the longest sequence of 1s
i = 1                                   #We can skip the first item since it's always work
length = 0
longest_length = 0
while i <= (hours - 1):
    if day[i] == str(1):
        length += 1
        i += 1
    else:
        if length > longest_length:     #if this is the best we've done, save it off
            longest_length = length
        length = 0
        i += 1
if length > longest_length:             #have to check again at the end, in case last hour was rest
    longest_length = length

print(longest_length)
