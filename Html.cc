<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Instagram Style App</title>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;500;700&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div id="login-screen" class="login-screen">
        <h1>Admin Login</h1>
        <input type="text" id="username" placeholder="Username">
        <input type="password" id="password" placeholder="Password">
        <button onclick="login()">Login</button>
        <p id="login-error" class="error"></p>
    </div>

    <div id="app" class="app" style="display:none;">
        <header>
            <h2>My App</h2>
            <button onclick="logout()">Logout</button>
        </header>

        <div class="post-form">
            <input type="text" id="post-text" placeholder="What's on your mind?">
            <input type="file" id="post-image" accept="image/*" onchange="previewImage(event)">
            <img id="image-preview" class="image-preview" style="display:none;" />
            <button onclick="createPost()">Post</button>
        </div>

        <div id="posts" class="posts"></div>
    </div>

    <script src="script.js"></script>
    <script>
        function login() {
            const username = document.getElementById('username').value;
            const password = document.getElementById('password').value;

            if (username === 'admin' && password === 'gn24@123') {
                document.getElementById('login-screen').style.display = 'none';
                document.getElementById('app').style.display = 'block';
            } else {
                document.getElementById('login-error').textContent = 'Invalid username or password';
            }
        }

        function logout() {
            document.getElementById('login-screen').style.display = 'flex';
            document.getElementById('app').style.display = 'none';
        }

        function previewImage(event) {
            const reader = new FileReader();
            reader.onload = function() {
                const preview = document.getElementById('image-preview');
                preview.src = reader.result;
                preview.style.display = 'block';
            }
            reader.readAsDataURL(event.target.files[0]);
        }
    </script>
</body>
</html>
