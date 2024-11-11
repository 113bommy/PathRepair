trash = input();
queue = [int(x) for x in input().split()];

queue = sorted(queue);
disappointed = 0;
waitTime = 0;
for i in range(len(queue)):
	if waitTime > queue[i]:
		disappointed += 1;
	else:
		waitTime += queue[i];
print(len(queue) - disappointed);