from sklearn.naive_bayes import GaussianNB
from sklearn.naive_bayes import BernoulliNB

data_file = open("data","r+")
data = [x.strip().split() for x in data_file.readlines()]
data.pop(0)

clable = []
for l in data:
	if(l[0]=='Consultancy'):
		l[0]=0
	elif(l[0]=='Service'):
		l[0]=1
	elif(l[0]=='Research'):
		l[0]=2
	
	clable.append(l[0])
	
	if(int(l[1])<30):
		l[1]=0
	elif(int(l[1])>=30):
		l[1]=1
		
	if(l[2]=='Ph.D.'):
		l[2]=0
	elif(l[2]=='BTech.'):
		l[2]=1
	elif(l[2]=='MTech.'):
		l[2]=2
		
	if(int(l[3])<10):
		l[3]=0
	elif(int(l[3])>=10):
		l[3]=1	
	
	l.pop(0)			

print(data)	
print(clable)
model = GaussianNB()
model.fit(data, clable)
#30,MTech,8
predicted= model.predict([[1,2,0]])

if(predicted == 0):
	print('Consultancy')
elif(predicted == 1):
	print('Service')
if(predicted == 2):
	print('Research')		
