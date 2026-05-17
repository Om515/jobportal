cd Downloads

chmod 600 filename_key.pem

ssh -i filename_key.pem azureuser@public_ip_address


sudo apt update

sudo apt install apache2 -y

cd /var/www/html

sudo nano index.html

sudo nano style.css

sudo nano script.js

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Azure Static Website</title>

    <link rel="stylesheet" href="style.css">
</head>
<body>

    <!-- Navbar -->
    <header>
        <h1>My Azure Website</h1>

        <nav>
            <a href="#">Home</a>
            <a href="#">About</a>
            <a href="#">Contact</a>
        </nav>
    </header>

    <!-- Hero Section -->
    <section class="hero">

        <h2>Welcome to My Cloud Website</h2>

        <p>
            This static website is hosted on an Azure Virtual Machine using Apache Server.
        </p>

        <button onclick="showMessage()">
            Click Me
        </button>

    </section>

    <!-- About Section -->
    <section class="about">

        <h2>About Project</h2>

        <p>
            This project demonstrates hosting a static website on Microsoft Azure VM.
            Technologies used: HTML, CSS, JavaScript, Apache2, Linux.
        </p>

    </section>

    <!-- Footer -->
    <footer>
        <p>Created by Om Satpute</p>
    </footer>

    <script src="script.js"></script>

</body>
</html>



*{
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

body{
    font-family: Arial, sans-serif;
    background-color: #f4f4f4;
}

/* Header */

header{
    background-color: #0078D7;
    color: white;

    display: flex;
    justify-content: space-between;
    align-items: center;

    padding: 20px 50px;
}

header nav a{
    color: white;
    text-decoration: none;
    margin-left: 20px;
    font-size: 18px;
}

header nav a:hover{
    text-decoration: underline;
}

/* Hero Section */

.hero{
    height: 80vh;

    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;

    text-align: center;

    background: linear-gradient(to right, #0078D7, #00BFFF);

    color: white;

    padding: 20px;
}

.hero h2{
    font-size: 50px;
    margin-bottom: 20px;
}

.hero p{
    font-size: 20px;
    max-width: 700px;
    margin-bottom: 30px;
}

.hero button{
    padding: 12px 25px;
    border: none;
    background-color: white;
    color: #0078D7;
    font-size: 18px;
    border-radius: 5px;
    cursor: pointer;
}

.hero button:hover{
    background-color: #f1f1f1;
}

/* About Section */

.about{
    padding: 60px 40px;
    text-align: center;
    background-color: white;
}

.about h2{
    margin-bottom: 20px;
    color: #0078D7;
}

.about p{
    font-size: 18px;
    line-height: 1.8;
}

/* Footer */

footer{
    background-color: #222;
    color: white;
    text-align: center;
    padding: 20px;
}


function showMessage(){

    alert("Website Successfully Hosted on Azure VM!");

}


