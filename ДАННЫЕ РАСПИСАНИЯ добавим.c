// --- ДАННЫЕ РАСПИСАНИЯ (добавим больше дней для примера) ---
const schedules = {
    "BL-25-9": {
        "Пн": [
            { time: "09:00", subject: "Основы программирования", room: "302" },
            { time: "10:30", subject: "Английский язык", room: "301" }
        ],
        "Вт": [
            { time: "09:00", subject: "Физика", room: "103" },
            { time: "10:30", subject: "Математика", room: "203" }
        ],
        "Ср": [
            { time: "11:00", subject: "Мировая история", room: "101" }
        ],
        "Чт": [
            { time: "09:00", subject: "География", room: "204" }
        ],
        "Пт": [
            { time: "10:00", subject: "Физкультура", room: "Спортзал" }
        ]
    }
};

// Функция отображения ВСЕХ дней
function renderSchedule(group) {
    const container = document.getElementById('schedule-list');
    container.innerHTML = '';
    const groupSchedule = schedules[group];

    if (!groupSchedule) {
        container.innerHTML = '<p>Нет данных.</p>';
        return;
    }

    // Перебираем дни недели
    const days = ["Пн", "Вт", "Ср", "Чт", "Пт"];
    days.forEach(day => {
        if (groupSchedule[day]) {
            const dayTitle = document.createElement('div');
            dayTitle.className = 'day-title';
            dayTitle.innerText = day;
            container.appendChild(dayTitle);

            groupSchedule[day].forEach(lesson => {
                const item = document.createElement('div');
                item.className = 'schedule-item';
                item.innerHTML = `
                    <span class="time">${lesson.time}</span>
                    <span class="subject">${lesson.subject}</span>
                    <span class="room">${lesson.room}</span>
                `;
                container.appendChild(item);
            });
        }
    });
}

// --- ЛОГИКА ЧАТА (простая) ---
const chatMessages = document.getElementById('chat-messages');
const chatInput = document.getElementById('chat-input');
const sendBtn = document.getElementById('send-btn');

function sendMessage() {
    const text = chatInput.value;
    if (text.trim() !== "") {
        const messageDiv = document.createElement('div');
        messageDiv.className = 'message student';
        messageDiv.innerHTML = `<strong>Вы:</strong> ${text}`;
        chatMessages.appendChild(messageDiv);
        chatInput.value = '';
        chatMessages.scrollTop = chatMessages.scrollHeight; // Прокрутка вниз
    }
}

sendBtn.addEventListener('click', sendMessage);
chatInput.addEventListener('keypress', (e) => { if(e.key === 'Enter') sendMessage(); });

// --- ИНИЦИАЛИЗАЦИЯ ---
document.getElementById('group-select').addEventListener('change', (e) => renderSchedule(e.target.value));

document.addEventListener('DOMContentLoaded', () => {
    renderSchedule("BL-25-9");
    // renderDeadlines(); // ...логика дедлайнов
});
// ... предыдущий код ...

// Функция для перехода в телеграм-бот
document.getElementById('go-to-bot').addEventListener('click', function() {
    // Вставьте сюда ссылку на вашего бота
    const botUrl = "https://t.me/@baget60som_bot";
    window.open(botUrl, '_blank'); // Открывает ссылку в новой вкладке
});

// ... остальной код ...
// Функция сохранения дедлайнов
function saveDeadlines() {
    localStorage.setItem('deadlines', JSON.stringify(deadlines));
}

// Функция загрузки дедлайнов при старте
function loadDeadlines() {
    const saved = localStorage.getItem('deadlines');
    if (saved) {
        deadlines = JSON.parse(saved);
        renderDeadlines();
    }
}

// Вызывай loadDeadlines() при загрузке страницы,
// а saveDeadlines() внутри функции добавления нового дедлайна.

