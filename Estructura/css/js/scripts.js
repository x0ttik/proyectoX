// Almacenar cuentas en localStorage (simulación)
const accounts = [
    { email: 'usuario1@example.com', password: 'contraseña123' },
    { email: 'usuario2@example.com', password: 'otracontraseña456' }
];

localStorage.setItem('accounts', JSON.stringify(accounts));
