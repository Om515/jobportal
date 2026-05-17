cd Downloads

chmod 600 filename_key.pem

ssh -i filename_key.pem azureuser@public_ip_address

sudo apt update

sudo apt upgrade -y

curl -fsSL https://deb.nodesource.com/setup_20.x | sudo -E bash -
sudo apt install -y nodejs

sudo apt install git -y

git clone https://github.com/om515/jobportal.git

git clone https://github.com/suyogtorase/ToDo.git

sudo apt install gnupg curl -y

curl -fsSL https://pgp.mongodb.com/server-7.0.asc | \
sudo gpg -o /usr/share/keyrings/mongodb-server-7.0.gpg \
--dearmor

echo "deb [ signed-by=/usr/share/keyrings/mongodb-server-7.0.gpg ] https://repo.mongodb.org/apt/ubuntu jammy/mongodb-org/7.0 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-7.0.list

sudo apt update

sudo apt install mongodb-org -y

sudo systemctl start mongod
sudo systemctl enable mongod


//for checking mongo
mongosh

//to quit 
quit


//go to frontend
npm i

//go to ToDo or that specific project and do 
npm i
npm run build
npm start



//set inbound rule in networking 
//port 5000 and TCP and name


//for mongosh

mongosh
show dbs
use dbname
show collections
db.collectionname.find()



///now onwards pm2

// first go to index.js and add two dots(..) at the beginning of frontend like (../frontend)

//now go to project example ToDo

npm run build 

cd .. //come to vm

sudo npm install -g pm2

pm2 start index.js --name "ToDoApp"

pm2 save

