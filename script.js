const skillLevels = document.querySelectorAll('.skill-level');

skillLevels.forEach(skill => {
  const level = parseInt(skill.getAttribute('data-level'));
  const maxWidthPercentage = 80; 
  
  const barWidthPercentage = (level / 100) * maxWidthPercentage;

  skill.style.width = barWidthPercentage + '%';
});


  

  