class Node:
	def __init__(self, num):
		self.num = num
		self.children = []
	
	def add_child(self, child):
		self.children.append(child)
		
	def is_leaf(self):
		return len(self.children) == 0
		
	def check_spruciness(self):
		if self.is_leaf():
			return True
		leafs = 0
		for child in self.children:
			if child.is_leaf():
				leafs += 1
			elif not child.check_spruciness():
				return False
		return (leafs == 3)
	
	def description(self):
		string = str(self.num) + "{"
		for child in self.children:
			string += child.description()
		return string + "}"
	
	
class Tree:
	def __init__(self, count, root):
		self.count = count
		self.root = root
		
	@classmethod
	def get_tree_from_array(cls, tree):
		assert len(tree) == tree[0]
		count = tree[0]
		tree = tree[1:]
		nodes = [Node(1)]
		for i in range(len(tree)):
			nodes.append(Node(i+1))
		
		for i in range(len(tree)):
			parentNum = tree[i] - 1
			if parentNum >= 0 and parentNum < len(nodes):
				nodes[parentNum].add_child(nodes[i+1])
			else:
				return None
				
		root = nodes[0]
		return cls(count=count, root=root)
		
	def check_spruce(self):
		if self.root.check_spruciness():
			print("Yes")
		else:
			print("No")
		

#list = [8,1,1,1,1,2,2,2] #yes
#list = [13,1,2,2,2,1,6,6,6,1,10,10,10] #no
#list = [7,1,2,2,1,1,1] #no
#list = [12,1,1,1,5,1,5,5,5,6,6,6] #yes

count = int(input())
list = [count]
for i in range(count - 1):
    x = int(input())
    list.append(x)
tree = Tree.get_tree_from_array(list)
tree.check_spruce()

