var express = require('express');
var router = express.Router();
var multer = require('multer');

/* GET home page. */
router.get('/', function(req, res, next) {
    res.render('index.ejs', { title: 'Express' });
});

router.get('/main', function(req, res, next){
    res.render('main');
});

router.get("/upload", function(req, res){
    res.render('upload');
});

router.post('/upload', function(req, res){
    res.send('uploaded');
});

module.exports = router;