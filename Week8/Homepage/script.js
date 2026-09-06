document.addEventListener("DOMContentLoaded", function () {
    // Greeting button on the home page
    const greetBtn = document.getElementById("greetBtn");
    if (greetBtn) {
        greetBtn.addEventListener("click", function () {
            const hour = new Date().getHours();
            let greeting = "Hello";
            if (hour < 12) {
                greeting = "Good morning";
            } else if (hour < 18) {
                greeting = "Good afternoon";
            } else {
                greeting = "Good evening";
            }
            alert(greeting + ", and welcome to my homepage!");
        });
    }
    // Random fun fact button on the hobbies page
    const factBtn = document.getElementById("factBtn");
    const funFact = document.getElementById("funFact");
    if (factBtn && funFact) {
        const facts = [
            "I've written over 1,000 lines of code in the past month.",
            "My favorite programming language so far is Python.",
            "I once stayed up until 3 AM debugging a single missing semicolon.",
            "I take my camera everywhere — even to the grocery store.",
            "I can solve a Rubik's cube in under two minutes."
        ];
        factBtn.addEventListener("click", function () {
            const randomIndex = Math.floor(Math.random() * facts.length);
            funFact.textContent = facts[randomIndex];
            funFact.style.fontWeight = "bold";
            funFact.style.color = "#0f3460";
        });
    }
    // Contact form validation and feedback
    const contactForm = document.getElementById("contactForm");
    const formAlert = document.getElementById("formAlert");
    if (contactForm) {
        contactForm.addEventListener("submit", function (event) {
            event.preventDefault();
            const name = document.getElementById("name").value.trim();
            const email = document.getElementById("email").value.trim();
            const message = document.getElementById("message").value.trim();
            if (!name || !email || !message) {
                alert("Please fill in all fields before submitting.");
                return;
            }
            if (!email.includes("@")) {
                alert("Please enter a valid email address.");
                return;
            }
            formAlert.classList.remove("d-none");
            contactForm.reset();
        });
    }
});
