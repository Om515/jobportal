cd Downloads

chmod 600 filename_key.pem

ssh -i filename_key.pem azureuser@public_ip_address

for vm 1 :

ip a

(after file transfer ):

ls 

cat filename.txt


for vm 2 :

echo "This is a sample file for transfer" > filename.txt

scp -i filename.txt azureuser@private_ip_address_of _vm1:/home/azureuser/

(After this it will ask for the password of vm1, enter the password and the file will be transferred to vm1)


