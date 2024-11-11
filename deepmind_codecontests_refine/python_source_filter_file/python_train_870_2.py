def main():
    n=int(input())
    dis=dict()
    tmp=list()
    tmp=input()
    tmp=tmp.split()
    for i in range(n):
        tmp[i]=int(tmp[i])
        dis[i+1]=tmp[i]
    tmp=[]
    number=int(input())
    for i in range(number):
        tmp=input()
        tmp=tmp.split()
        box_num=int(tmp[0])
        bird_num=int(tmp[1])
        if box_num ==1:
            dis[0]=dis[1]-bird_num
            if n >1:
                dis[2]+=dis[1]
            dis[1]=0
        elif box_num == len(dis):
            dis[box_num]=bird_num-1
            dis[box_num-1]+=dis[box_num]
            dis[box_num]=0
        else:
            dis[box_num-1]+=bird_num-1
            dis[box_num+1]+=dis[box_num]-bird_num
            dis[box_num]=0
    for i in range(1,n+1):
        print(dis[i])
        



if __name__ == "__main__":
    main()