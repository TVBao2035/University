var btnSubmit = document.querySelector('.btn_submit');
var form = document.querySelector('.container')
var firstNameInput = document.querySelector('.first_name--input');
var lastNameInput = document.querySelector('.last_name--input');
var emailInput = document.querySelector('.email--input');
var reEnterEmail = document.querySelector('.re-enter_email--input');
var genderInput = document.querySelector('.gender--input')
var birthday = document.querySelector('.birthday--input');
var password = document.querySelector('.password--input');
var blockDisplayMessageError = document.querySelector('.display_messeage--error');
btnSubmit.onclick = ()=>{
    console.log(btnSubmit);
    blockDisplayMessageError.innerHTML = "";
    if(firstNameInput.value.trim().length === 0 ||lastNameInput.value.trim().length === 0|| emailInput.value.trim().length === 0||reEnterEmail.value.trim().length === 0 || birthday.value.trim().length === 0 || password.value.trim().length === 0){
        if(firstNameInput.value.trim().length === 0){
            blockDisplayMessageError.innerHTML +=  "<br>First Name  không được để trống!<br>";
    
        }
    
        if(lastNameInput.value.trim().length === 0){
            blockDisplayMessageError.innerHTML += "<br>Last Name  không được để trống!<br>";
    
        }
    
        if(emailInput.value.trim().length === 0){
            blockDisplayMessageError.innerHTML += "<br>Email không được để trống!<br>";
    
        }else if(/^[A-Za-z][\w$.]+@[\w]+\.\w+$/.test(emailInput.value) === false){
            blockDisplayMessageError.innerHTML += "<br>Email không hop le!<br>";
    
        }
    
        if(reEnterEmail.value.trim().length === 0){
            blockDisplayMessageError.innerHTML += "<br>Re-Enter Email không được để trống!<br>";
    
        }else if(reEnterEmail.value !== emailInput.value){
            blockDisplayMessageError.innerHTML += "<br>Re-Enter Email không khớp!<br>"
    
        }
    
        if(birthday.value.trim().length === 0){
            blockDisplayMessageError.innerHTML += "<br>Vui Lòng nhập ngày tháng năm sinh!<br>";
    
        }
    
        if(password.value.trim().length === 0){
            blockDisplayMessageError.innerHTML += "<br>Vui Lòng nhập Passowrd!<br>"
    
        }

    }else{
        alert(`First name: ${firstNameInput.value} \nLast name: ${lastNameInput.value}\nEmail: ${emailInput.value}\nRe-enter email: ${reEnterEmail.value}\nPassword: ${password.value}\nI am ${genderInput.value}\nBirthday: ${birthday.value}`)
    }
}