// Shared quiz engine. Each .q has data-a="index of correct option" and optional .ex explanation
function checkAll(okTxt, badTxt, scoreTxt){
  let qs=document.querySelectorAll('.q'),s=0;
  qs.forEach((q,i)=>{
    let c=q.querySelector('input:checked'),fb=q.querySelector('.fb');
    let ex=q.dataset.ex||'';
    if(c && c.value==q.dataset.a){s++;fb.style.color='var(--ok)';fb.textContent=okTxt+' '+ex}
    else{fb.style.color='var(--bad)';fb.textContent=badTxt+' '+String.fromCharCode(65+ +q.dataset.a)+'. '+ex}
  });
  document.getElementById('score').textContent=scoreTxt+': '+s+' / '+qs.length;
}
function resetAll(){document.querySelectorAll('.q input').forEach(i=>i.checked=false);document.querySelectorAll('.fb').forEach(f=>f.textContent='');document.getElementById('score').textContent=''}
document.addEventListener('DOMContentLoaded',()=>{
  document.querySelectorAll('.q').forEach((q,i)=>{
    q.querySelectorAll('label').forEach((l,j)=>{
      l.insertAdjacentHTML('afterbegin',`<input type="radio" name="q${i}" value="${j}"> ${String.fromCharCode(65+j)}. `);
    });
    q.insertAdjacentHTML('beforeend','<div class="fb"></div>');
  });
});
