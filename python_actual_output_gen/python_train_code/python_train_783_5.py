nums = input()
nums = nums.strip("\n")
nums = nums.split()
length = int(nums[0])
jump = int(nums[1])
track = input()
track = track.strip("\n")
track = list(track)
 
grasshopP = track.index("G")
insectP = track.index("T")
 
def doIt(grasshopPos, insectPos):
    if(grasshopPos <= insectPos):
        while grasshopPos <= insectPos and grasshopPos < length:
            if(track[grasshopPos] == "#"):
                print("NO")
                return
            if(grasshopPos == insectPos):
                print("YES")
                return
            grasshopPos += jump
        print("NO")
    else:
        while grasshopPos >= insectPos and grasshopPos > 0:
            if(track[grasshopPos] == "#"):
                print("NO")
                return
            if(grasshopPos == insectPos):
                print("YES")
                return
            grasshopPos -= jump
        print("NO")
 
doIt(grasshopP, insectP)